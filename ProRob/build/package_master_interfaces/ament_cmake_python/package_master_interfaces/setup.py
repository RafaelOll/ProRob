from setuptools import find_packages
from setuptools import setup

setup(
    name='package_master_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('package_master_interfaces', 'package_master_interfaces.*')),
)
