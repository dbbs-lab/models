import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
     name='dbbs-models',
     version='0.1.1',
     author="Robin De Schepper, Alice Geminiani, Elisa Marenzi, Stefano Casali, Alberto Antonietti, Claudia Casselato, Egidio D'Angelo",
     author_email="robingilbert.deschepper@unipv.it",
     description="Collection of neuron models for the NEURON simulator",
     long_description=long_description,
     long_description_content_type="text/markdown",
     url="https://github.com/dbbs-lab/models",
     license='GPLv3',
     packages=setuptools.find_packages(),
     classifiers=[
         "Programming Language :: Python :: 3",
         "Operating System :: OS Independent",
     ],
     install_requires=[
        "nrn-glia>=0.1.7",
        "dbbs-mod-collection>=0.0.1",
        "nrn-patch>=0.0.2"
     ]
 )
