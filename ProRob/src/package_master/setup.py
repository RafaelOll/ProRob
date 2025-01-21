from setuptools import find_packages, setup

package_name = 'package_master'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='rouillon',
    maintainer_email='raf3615@gmail.com',
    description='projet robotique',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'service_test = package_master.service_member_function:main',
            'service_drone = package_master.drone_node:main',
            'service_tb = package_master.tb_node:main',
            'client = package_master.master_node:main',
            'client_drone = package_master.master_node_drone:main',
            'client_tb = package_master.master_node_tb:main',

        ],
    },
)
