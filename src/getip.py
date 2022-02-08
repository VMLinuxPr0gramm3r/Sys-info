import os
import socket
import distro
import getpass
import platform
from requests import get
import uuid
import time
import psutil
from torip import ip_list

public_ip = get('https://api.ipify.org').text
print("public ip adress: ",public_ip)
if(public_ip in ip_list):
    print("tor status: true")
else:
    print("tor status: false")
