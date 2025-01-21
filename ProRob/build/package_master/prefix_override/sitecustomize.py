import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/rouillon/Documents/ProDroneTB/ProRob/install/package_master'
