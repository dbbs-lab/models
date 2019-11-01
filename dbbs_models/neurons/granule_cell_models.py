#Made by Stefano "Bremen" Masoli
# Modified & updated by Elisa Marenzi

import numpy as np
from neuron import h
from ..synapses import Synapse




class RegularGranuleCell:
    def __init__(self, x, y, z_coord, record_all = 1, Dt = 0.1):
	# def __init__(self,position, record_all = 1, Dt = 0.1):

        self.record_all = 1
        self.vext_record_all = 0
        self.ionic_record_all = 1



#Soma channels
        self.soma=h.Section(name='soma_grc')
        self.soma.L = 5.62232
        self.soma.nseg = 1 + (2 * int(self.soma.L / 40))
        self.soma.diam = 5.8
        self.soma.Ra = 100
        self.soma.cm = 2

        self.soma.insert('Leak')
        self.soma.gmax_Leak = 0.00029038073716
        self.soma.e_Leak = -60

        self.soma.insert('Kv3_4')
        self.soma.gkbar_Kv3_4 = 0.00076192450951999995


        self.soma.insert('Kv4_3')
        self.soma.gkbar_Kv4_3 = 0.0028149683906099998
        self.soma.ek = -88

        self.soma.insert('Kir2_3')
        self.soma.gkbar_Kir2_3 = 0.00074725514701999996


        self.soma.insert('GRC_CA')
        self.soma.gcabar_GRC_CA = 0.00060938071783999998

        self.soma.insert('Kv1_1')
        self.soma.gbar_Kv1_1 =  0.0056973826455499997

        self.soma.insert('Kv1_5')
        self.soma.gKur_Kv1_5 =  0.00083407556713999999

        self.soma.insert('Kv2_2_0010')
        self.soma.gKv2_2bar_Kv2_2_0010 = 1.203410852e-05

        self.soma.insert('cdp5_CR')

        self.soma.push()
        self.soma.eca = 137.5
        h.pop_section()

        # h.pt3dadd(0.0, 0, 0.0, self.soma.diam)
		# h.pt3dadd(0.0, 5.62232, 0.0, self.soma.diam)
        h.pt3dadd(x, y, z_coord, self.soma.diam)
        h.pt3dadd(x, (y + 5.62232), z_coord, self.soma.diam)

        self.whatami = 'GrC2018'

        # h.celsius=30


#DEND
        self.dend = [h.Section(name='dend_'+str(x)) for x in range(4)]

        for i in self.dend:
            i.L = 15
            i.nseg = 1 + (2 * int(i.L / 40))
            i.diam = 0.75
            i.Ra = 100
            i.cm = 2.5

            i.insert('Leak')
            i.gmax_Leak = 0.00025029700736999997
            i.e_Leak =  -60

            i.insert('GRC_CA')
            i.gcabar_GRC_CA = 0.0050012800845900002

            i.insert('Kca1_1')
            i.gbar_Kca1_1 = 0.010018074546510001
            i.ek = -88

            i.insert('Kv1_1')
            i.gbar_Kv1_1 = 0.00381819207934


            i.insert('cdp5_CR')

            i.push()
            i.eca = 137.5
            h.pop_section()


        for j in self.dend:
            j.connect(self.soma,0,0)


#hill
        self.hill=h.Section(name='hill')
        self.hill.L = 1
        self.hill.nseg = 1
        self.hill.diam = 1.5
        self.hill.Ra = 100
        self.hill.cm = 2

        self.hill.insert('Leak')
        self.hill.gmax_Leak = 0.00036958189720000001
        self.hill.e_Leak =  -60

        self.hill.insert('GRC_NA_FHF')
        self.hill.gnabar_GRC_NA_FHF = 0.0092880585146199995
        self.hill.ena = 87.39

        self.hill.insert('Kv3_4')
        self.hill.gkbar_Kv3_4 = 0.020373463109149999
        self.hill.ek = -88

        self.hill.insert('GRC_CA')
        self.hill.gcabar_GRC_CA = 0.00057726155447

        self.hill.insert('cdp5_CR')

        self.hill.push()
        self.hill.eca = 137.5
        # h.pt3dadd(0.0, 5.62232, 0.0, self.hill.diam)
		# h.pt3dadd(0.0, 6.62232, 0.0, self.hill.diam)
        h.pt3dadd(x, (y + 5.62232), z_coord, self.hill.diam)
        h.pt3dadd(x, (y + 6.62232), z_coord, self.hill.diam)
        h.pop_section()




#AIS
        self.ais=h.Section(name='AIS')
        self.ais.L = 10
        self.ais.nseg = 1
        self.ais.diam = 0.7
        self.ais.Ra = 100
        self.ais.cm = 1

        self.ais.insert('GRC_NA_FHF')
        self.ais.gnabar_GRC_NA_FHF = 1.28725006737226
        self.ais.ena = 87.39

        self.ais.insert('Kv3_4')
        self.ais.gkbar_Kv3_4 = 0.0064959534065400001
        self.ais.ek = -88

        self.ais.insert('Leak')
        self.ais.gmax_Leak = 0.00029276697557000002
        self.ais.e_Leak =  -60


        self.ais.insert('GRC_CA')
        self.ais.gcabar_GRC_CA =  0.00031198539471999999

        self.ais.insert('GRC_KM')
        self.ais.gkbar_GRC_KM =  0.00056671971737000002

        self.ais.insert('cdp5_CR')


        self.ais.push()
        self.ais.eca = 137.5

        # h.pt3dadd(0.0, 6.62232, 0.0, self.ais.diam)
		# h.pt3dadd(0.0, 16.62232, 0.0, self.ais.diam)
        h.pt3dadd(x, (y + 6.62232), z_coord, self.ais.diam)
        h.pt3dadd(x, (y + 16.62232), z_coord, self.ais.diam)
        h.pop_section()


        lensec = 7
        secnumber_aa = int(126/lensec)
        secnumber_pf = int(1000/lensec)

#Axon
#Ascending
        self.HD_aa = [h.Section(name='HD_aa_'+str(x)) for x in range(secnumber_aa)]
        for b in self.HD_aa:
            b.L = lensec
            b.nseg = 1
            b.diam = 0.3
            b.Ra = 100
            b.cm = 1


            b.insert('GRC_NA')
            b.gnabar_GRC_NA = 0.026301636815019999
            b.ena = 87.39

            b.insert('Kv3_4')
            b.gkbar_Kv3_4 = 0.00237386061632
            b.ek = -88

            b.insert('Leak')
            b.gmax_Leak =  9.3640921249999996e-05
            b.e_Leak =  -60

            b.insert('GRC_CA')
            b.gcabar_GRC_CA = 0.00068197420273000001

            b.insert('cdp5_CR')

            b.push()
            b.eca = 137.5

            len_ini = 16.62232
            len_end = 7

            # h.pt3dadd(0.0, len_ini , 0.0, b.diam)
			# h.pt3dadd(0.0, len_ini + len_end, 0.0, b.diam)
            h.pt3dadd(x, (y + len_ini), z_coord, b.diam)
            h.pt3dadd(x, (y + len_ini + len_end), z_coord, b.diam)
            h.pop_section()

            len_ini = len_ini + len_end

#parallel fiber
        self.HD_pf1 = [h.Section(name='HD_pf_'+str(x)) for x in range(secnumber_pf)]

        for i in self.HD_pf1:
            i.L = lensec
            i.nseg = 1
            i.diam = 0.15
            i.Ra = 100
            i.cm = 1


            i.insert('GRC_NA')
            i.gnabar_GRC_NA = 0.017718484492610001
            i.ena = 87.39

            i.insert('Kv3_4')
            i.gkbar_Kv3_4 = 0.0081756804703699993
            i.ek = -88

            i.insert('Leak')
            i.gmax_Leak = 3.5301616000000001e-07
            i.e_Leak =  -60

            i.insert('GRC_CA')
            i.gcabar_GRC_CA = 0.00020856833529999999

            i.insert('cdp5_CR')

            i.push()
            i.eca = 137.5

            len_ini = 142.62232
            len_end = 7

            # h.pt3dadd(len_ini, len_ini , 0.0, i.diam)
            # h.pt3dadd(len_ini + len_end, len_ini , 0.0, i.diam)
            h.pt3dadd((x + len_ini), (y + len_ini), z_coord, i.diam)
            h.pt3dadd((x + len_ini + len_end), (y + len_ini), z_coord, i.diam)
            h.pop_section()

            len_ini = len_ini + len_end



        self.HD_pf2 = [h.Section(name='HD_pf_'+str(x)) for x in range(secnumber_pf)]
        for z in self.HD_pf2:
            z.L = lensec
            z.nseg = 1
            z.diam = 0.15
            z.Ra = 100
            z.cm = 1


            z.insert('GRC_NA')
            z.gnabar_GRC_NA = 0.017718484492610001
            z.ena = 87.39

            z.insert('Kv3_4')
            z.gkbar_Kv3_4 = 0.0081756804703699993
            z.ek = -88

            z.insert('Leak')
            z.gmax_Leak = 3.5301616000000001e-07
            z.e_Leak =  -60

            z.insert('GRC_CA')
            z.gcabar_GRC_CA = 0.00020856833529999999


            z.insert('cdp5_CR')


            z.push()
            z.eca = 137.5

            len_ini = 142.62232
            len_end = 7

            # h.pt3dadd(len_ini, len_ini , 0.0, i.diam)
            # h.pt3dadd(len_ini - len_end, len_ini , 0.0, i.diam)
            h.pt3dadd((x + len_ini), (y + len_ini), z_coord, i.diam)
            h.pt3dadd((x + len_ini - len_end), (y + len_ini), z_coord, i.diam)
            h.pop_section()

            len_ini = len_ini - len_end



#Connections

        self.hill.connect(self.soma,0,0)
        self.ais.connect(self.hill,1,0)


#AA
        for j in range(secnumber_aa-1):
            l = j+1
            #print(j,l  )
            self.HD_aa[l].connect(self.HD_aa[j],1,0)
#PF
        for i in range(secnumber_pf-1):
            l = i+1
            #print(i,l  )
            self.HD_pf1[l].connect(self.HD_pf1[i],1,0)
            self.HD_pf2[l].connect(self.HD_pf2[i],1,0)

            self.HD_pf1[0].connect(self.HD_aa[secnumber_aa-1],1,0)
            self.HD_pf2[0].connect(self.HD_aa[secnumber_aa-1],1,0)

            self.HD_aa[0].connect(self.ais,1,0)

#Time and voltage vectors
        # self.time_vector = h.Vector()
        # self.time_vector.record(h._ref_t)

        # self.vm = h.Vector()
        # self.vm.record(self.soma(0.5)._ref_v)

        self.createsyn(4)


        self.MF_L = []
        # self.GOC_L = []
        self.mfncpc = []
        # self.gocncpc = []

        self.spike = h.NetStim(0.5, sec= self.soma)
		#self.spike.start = -10
        #self.spike.number = 1
        #self.spike.interval = 1e9
        self.nc_spike = h.NetCon(self.soma(1)._ref_v, self.spike,-20,0,1, sec = self.soma)



		# Recording vectors
        if self.record_all:
            self.record = {}

            self.record['spk'] = h.Vector()
            self.nc_spike.record(self.record['spk'])

            self.record['time'] = h.Vector()
            self.record['time'].record(h._ref_t)

            self.record['vm'] = h.Vector()
            self.record['vm'].record(self.soma(.5)._ref_v, sec = self.soma)



#NEW SYNAPSES
    def createsyn(self, nsyn_MF_AMPA):

        self.MF_GrC = []
        self.MF_GrC_mossy = []

        for x in range(0,nsyn_MF_AMPA):
            self.MF_GrC.append(Synapse('mossy',self,self.dend[x]))    			# ampa
            self.MF_GrC_mossy.append(Synapse('mossynmda',self,self.dend[x])) 	# nmda

            #Gaba - DA METTERE A POSTO CON STE
            # self.GoC_GrC.append(Synapse('GoC',self,self.dend[x])) 				# gaba: never been tested on this new multicomp



### PROVA ###
    def pconnect(self,source,type_syn):
        if type_syn == 'mf':
            #source = int(source)
            for mf_l in self.MF_GrC:	# ampa connection type
                self.mfncpc.append(h.NetCon(source, mf_l.input))
                self.mfncpc[-1].delay = 1
                self.mfncpc[-1].weight[0] = 1
            return self.mfncpc#[-1]
            for mf_l in self.MF_GrC_mossy:	# nmda connection type
                self.mfncpc.append(h.NetCon(source, mf_l.input))
                self.mfncpc[-1].delay = 1
                self.mfncpc[-1].weight[0] = 1
            return self.mfncpc
        # if type_syn == 'goc':
            # #source = int(source)
            # # print("syn_len ", len(self.GOC_L), syn_idx, self.whatami, source)
            # for goc_l in self.GOC_L:
                # self.gocncpc.append(h.NetCon(source.spike, goc_l.input))
                # self.gocncpc[-1].delay = 1
                # self.gocncpc[-1].weight[0] = 1
            # return self.gocncpc#[-1]



    def destroy(self):
        del self.nc_spike
        for m in self.MF_L:
            m.destroy()
            del m
        # for m in self.GOC_L:
            # m.destroy()
            # del m
        for m in self.mfncpc:
            del m
        # for m in self.gocncpc:
            # del m
        del self
