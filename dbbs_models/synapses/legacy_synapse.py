#Original code, Sergio Solinas.
#Adapted by Stefano Masoli

from neuron import h

class Synapse:
    def __init__(self,source,target,section,nrel = 0,syntype = 'ANK',record_all = 0,weight = 1):
        self.record_all = record_all
        if record_all:
            print("Recording all in Synapse")

        self.input = h.NetStim(0.5)
        self.input.start = -10
        self.input.number = 1
        self.input.interval = 1e9
        self.weight = weight

        self.nrel = nrel
        self.syntype = syntype

        self.postsyns = {}

        if (type(source) == type('s')):
            sourcetype = source
        else:
            sourcetype = source.whatami

        if self.record_all:
            self.SpikeTrain_input = [h.Vector(),h.Vector()]
            self.netcon_in = h.NetCon(self.input,None, 0, 0.1, 1)
            self.netcon_in.record(self.SpikeTrain_input[1], self.SpikeTrain_input[0], 1)

#granule
        if sourcetype == 'mossy':
            if target.whatami == 'GrC2018':
                # Make a mossy synapse onto a granule cells
                # Use deterministic synapses*
                self.whatami = "syn_mossytoGrC_det"
                self.postsyns['AMPA'] = [h.GRANULE_Ampa_det_vi(0.9, sec=section)]
                self.postsyns['AMPA'][0].tau_facil=5
                self.postsyns['AMPA'][0].tau_rec=8
                self.postsyns['AMPA'][0].tau_1=1
                self.postsyns['AMPA'][0].gmax = 1200
                self.postsyns['AMPA'][0].U=0.43
                #print('grc ampa')
                self.nc_syn = [h.NetCon(self.input,receptor[0],0,0.1,1) for receptor in self.postsyns.values()]

        elif sourcetype == 'mossynmda':
            if target.whatami == 'GrC2018':
                # Make a mossy synapse onto a granule cells
                # Use deterministic synapses*
                self.whatami = "syn_mossytoGrC_det_nmda"
                self.postsyns['NMDA'] = [h.GRANULE_Nmda_det_vi(0.9, sec=section)]
                self.postsyns['NMDA'][0].tau_facil=5
                self.postsyns['NMDA'][0].tau_rec=8
                self.postsyns['NMDA'][0].tau_1=1
                self.postsyns['NMDA'][0].gmax = 18800
                self.postsyns['NMDA'][0].U=0.43
                #print('grc nmda')
                self.nc_syn = [h.NetCon(self.input,receptor[0],0,0.1,1) for receptor in self.postsyns.values()]

        elif sourcetype == 'GoC':
            if target.whatami == 'GrC2018':
                self.whatami = "syn_GoCtoGrC_exp"
                self.postsyns['GABA'] = [h.GRANULE_Gaba_det_vi(1, sec=section)]
                self.postsyns['GABA'][0].U = 0.35
                self.nc_syn = [h.NetCon(self.input.newnetstim,receptor[0],0,0.1,1) for receptor in self.postsyns.values()]
                # print('gaba')

        else:
            print('SOURCE TYPE DOES NOT EXIST SOMETHING WRONG!!!!!!!!!')


    def prel(self,prel):
        for r in self.release_sites:
            r.U = 0.42

    def destroy(self):
        if self.record_all:
            del self.netcon_in
        if self.nrel > 0:
            for r in self.netcon_out:
                del r
            for r in self.nc_rel:
                del r
        if self.whatami == "syn_grc2stl_relay" or self.whatami == "syn_pf2stl_relay":
            del self.relay
        for r in self.nc_syn:
            del r
        del self
