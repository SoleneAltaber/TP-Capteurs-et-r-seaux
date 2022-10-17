# TP-Capteurs-et-reseaux
TP ESE de capteurs et réseaux

FRAYSSE Corentin 
ALTABER Solène

**1. TP 1: BUS I²C**

On cherche à piloter le capteur BMP280 DIGITAL PRESSURE SENSOR en I²C.

 - Le protocole I²C

Rappel I²C: C’est un bus série synchrone bidirectionnel half-duplex :</br>
Ainsi, on remarque que le Bus I²C est nécessairement composé de 3 fils : SCL (une clock), SDA (le bus de données) et une Masse.</br>
De plus, il nécessite la présence d’un MASTER qui peut prendre le contrôle du bus et envoyer des requêtes (écriture ou lecture) à des SLAVES (repérable par une “SLAVE Address qui est propre à chaque composants) à travers le bus de données SDA. </br>
SDA possède 6 états possibles: IDLE, START, STOP, 0, 1, ACK (et RESTART et NACK)</br>
On change d’état lors des fronts montants de la clock (SCL) afin d’avoir un protocole synchrone. Le signal SDA est tiré à 1 par une résistance de pull up, les composants (MASTER ou SLAVES) ne peuvent qu’appliquer des 0 ou libérer le bus qui repasse à 1 si aucun autre composant ne le tire à 0.</br>

 - Le capteur

Dans ce TP n°1 nous utiliserons le capteur BMP280 :  DIGITAL PRESSURE SENSOR : </br>
Slave adress : 111011X      → le X est déterminé par le câblage du capteur: si SDO est connecté au GND on aura X=0 si SDO est connecté au VDDIO on aura X=1.</br>
                            → en WRITE : 111011X0 </br>
                            → en READ : 111011X1              ( le dernier Bit indique si le MASTER veut appelle les SLAVE pour une requête de lecture ou écriture)</br>
Registre d'identification du composant : chip_id[7:0] est à l'adresse 0xD0 est contient la valeur 0x58.</br>
Registre déterminant le mode de fonctionnement du capteur : mode[1:0] est à l'adresse 0xF4 est contient la valeur 11 pour est en normal mode.</br>
Registres d'étalonnage du composant: 0xA1 à 0x88. </br>
Registres contenant la température (ainsi que le format): temp_xlsb[7:0] est à l'adresse 0xFC,  temp_lsb[7:0] est à l'adresse 0xFB,   temp_msb[7:0] est à l'adresse 0xFA. </br>
Registres  contenant la pression (ainsi que le format): press_xlsb[7:0] est à l'adresse 0xF9,  press_lsb[7:0] est à l'adresse 0xF8,   press_msb[7:0] est à l'adresse 0xF7. </br>
Fonctions permettant le calcul de la température et de la pression compensées, en format entier 32 bits: bmp280_compensate_T_double (BMP280_S32_t adc_T) pour la temperature et bmp280_compensate_P_double (BMP280_S32_p adc_P) pour la pression.</br>


**2. TP 2:  Interfaçage STM32 - Raspberry**

Comment le Raspberry a obtenu son adresse IP? Le reseau est : 192.168.88.0/24 ainsi le reseau peut posséder jusqu'a 2^8 machines. C'est le routeur qui attribut une adresse IP aux RPI


etapes effectuées au cours du TP 2
- On a flashé la carte à l'aide de RPI-imager
- On s'est connecté au reseau 192.168.88.0/24 en ssh 
- On a obtenu l'adresse IP : 192.168.88.242
- On a modifié les fichiers config.txt et cmdline.txt tel que decrit dans le TP
- On a installé minicom (sudo apt-get install minicom) 
- En rebouclant le RX de la carte son son TX, on a reussi a envoyer et recevoir des chaînes de caractères
- On a connecté de RX de la RPI au TX de la nucléo et inverssement pour pouvoir les faires communiqué lun avec l'autre




