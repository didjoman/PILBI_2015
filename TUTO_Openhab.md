Installer Openhab (par curiosité) : 
===================================
/!\ Cette étape n'est pas nécessaire, c'est uniquement si vous avec besoin de recommencer un projet from scratch.

1 _ Télécharger les fichiers "Runtime Core", "Addons" et "Demo Setup" sur la page : http://www.openhab.org/getting-started/downloads.html
2 _ Dans cet ordre (et dans un dossier vide) :
  Unziper runtime > unzip demo

3 _ Ensuite :
  > cp configurations/openhab_default.cfg configurations/openhab.cfg

4 _ Démarrer Openhab :
  > ./start.sh

5 _ Admirer la démo :
   > firefox http://127.0.0.1:8080/openhab.app?sitemap=demo


Utiliser le Raspberry Pi : 
==========================

1 _ Mettre la carte SD dans le Raspberry Pi
2 _ Brancher un cable réseau du Raspberry Pi jusqu'au rooter
3 _ Brancher l'alimentation du Raps. (micro-usb <-> USB) jusqu'à l'ordi.

4 _ L'ordi et le Rasp. doivent être sur le même réseau / sous-réseau.
    Le mieux est de brancher l'ordi sur le rooter si on utilise un réseau public (de type école ...)
5 _ Ensuite sur l'ordi, on recherche le Raspberry sur le réseau : 
    a _ > hotsname -I  # donne les adresses de la machine, prendre celle qui commence par 195.
    b _ > nmap -sn 195.221.227.0/24  # recherche les machines présentes sur le sous réseau (il doit y en avoir au moins 2, le votre et le Rasp.).
    c _ > ssh pi@195.221.227.124  # mdp : raspberry

# Ça y est ! Vous êtes sur le Raspberry !  


Partager l'écran du Raspberry
=============================

Il peut être utile de vouloir partager l'écran du Rasp. si vous n'êtes pas à l'aise avec la ligne de commande, ou si vous voulez exécuter une application graphique.

Une fois sur le Rasp. (avec SSH par exemple) :

1 _ Démarrer le serveur VNC (sur le Rasp) : 
  > vncserver :1 -geometry 1024x600 -depth 16 -pixelformat rgb565
 
2 _ Sur l'ordi relié au même sous réseau :
  > vncviewer 195.221.227.124:5901 

# Ça y est ! Vous devriez voir appraitre l'écran du Rasp !  


Démarrer Openhab :
==================

1 _ Démarrer Openhab :
  > ./start.sh

2 _ Admirer le résultat :
   > firefox http://195.221.227.124:8080/openhab.app?sitemap=demo

