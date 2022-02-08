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

def main():
  ldistro = distro.id()
  public_ip = get('https://api.ipify.org').text
  operating_system = platform.system()

  print("Hostname: " + socket.gethostname())
  print("=======================================================================================================================")
  print("operating_system: "+operating_system)
  if(operating_system == "Windows"):
      pass
  elif(operating_system == "Linux"):
   #print("=======================================================================================================================")
      print("Linux distribution: "+ldistro)
      if(ldistro == "debian"):
          dupdate = input("do you want to update your system? [y/n]: ")
          if(dupdate == "y"):
              os.system("sudo apt update && sudo apt full-upgrade")
          else:
              pass 
      elif(ldistro == "fedora"):
          fupdate = input("do you want to update your system? [y/n]: ")
          if(fupdate == "y"):
              os.system("sudo dnf update; sudo dnf autoremove")
          else:
              pass
      elif(ldistro == "arch"):
          aupdate = input("do you want to update your system? [y/n]: ")
          if(aupdate == "y"):
              os.system("sudo pacman -Syu")
          else:
              pass
      else:
          pass

  elif(operating_system == "Mac OS X"):
      pass
  else:
      pass
  print("=======================================================================================================================")
  print("username: "+getpass.getuser())
  print("=======================================================================================================================")
  print("platform: "+platform.platform())
  print("=======================================================================================================================")
  print("public ip_adress: " + public_ip)
  if(public_ip in ip_list):
    print("This machine is using tor")
  else:
    print("This machine is not using tor")
  print("=======================================================================================================================")
  print("Active network interfaces :")
  f = open('/proc/net/dev','r')
  ifacelist = f.read().split('\n') 
  f.close()
  ifacelist.pop(0)
  #ifacelist.pop(0)
  for line in ifacelist:

      ifacedata = line.replace(' ','').split(':')

      if len(ifacedata) == 2:

          if int(ifacedata[1]) > 0:

              print(ifacedata[0])

  print("=======================================================================================================================")
  print ("MAC Adress: ", end="")
  print (':'.join(['{:02x}'.format((uuid.getnode() >> ele) & 0xff)
  for ele in range(0,8*6,8)][::-1]))
  print("=======================================================================================================================")
  print("memory (in bytes):")
  print(psutil.virtual_memory().total)
  cpu_usage = psutil.cpu_percent(4)
  print('The CPU usage: ',  cpu_usage," %")
  
if __name__ == "__main__":
  main()
