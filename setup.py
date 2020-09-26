import os
import setuptools

with open(os.path.join(os.path.dirname(__file__), "dbbs_models", "__init__.py"), "r") as f:
    for line in f:
        if "__version__ = " in line:
            exec(line.strip())
            break

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
     name='dbbs-models',
     version=__version__,
     author="Martina Rizza, Stefano Masoli, Robin De Schepper, Egidio D'Angelo",
     author_email="robingilbert.deschepper@unipv.it",
     description="Collection of neuron models for the NEURON simulator",
     long_description=long_description,
     long_description_content_type="text/markdown",
     url="https://github.com/dbbs-lab/models",
     include_package_data=True,
     package_data={
         # If any package contains *.txt or *.rst files, include them:
         "": ["morphologies/*.asc", "morphologies/*.swc"],
     },
     license='GPLv3',
     packages=setuptools.find_packages(),
     classifiers=[
         "Programming Language :: Python :: 3",
         "Operating System :: OS Independent",
     ],
     install_requires=[
        "arborize>=1.1.4",
        "nrn-glia>=0.3.5",
        "dbbs-mod-collection>=1.0.1",
        "nrn-patch>=2.1.1",
     ],
     extras_require={
        'dev': ['efel']
     }
 )
