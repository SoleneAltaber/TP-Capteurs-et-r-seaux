# TP-Capteurs-et-reseaux
TP ESE de capteurs et réseaux

FRAYSSE Corentin 
ALTABER Solène

**1. TP 1: BUS I²C**

On cherche à piloter le capteur BMP280 DIGITAL PRESSURE SENSOR en I²C.

 - Le protocole I²C

Rappel I²C: C’est un bus série synchrone bidirectionnel half-duplex :
Ainsi, on remarque que le Bus I²C est nécessairement composé de 3 fils : SCL (une clock), SDA (le bus de données) et une Masse.
De plus, il nécessite la présence d’un MASTER qui peut prendre le contrôle du bus et envoyer des requêtes (écriture ou lecture) à des SLAVES (repérable par une “SLAVE Address qui est propre à chaque composants) à travers le bus de données SDA. 
SDA possède 6 états possibles: IDLE, START, STOP, 0, 1, ACK (et RESTART et NACK)
On change d’état lors des fronts montants de la clock (SCL) afin d’avoir un protocole synchrone. Le signal SDA est tiré à 1 par une résistance de pull up, les composants (MASTER ou SLAVES) ne peuvent qu’appliquer des 0 ou libérer le bus qui repasse à 1 si aucun autre composant ne le tire à 0.

 - Le capteur

Dans ce TP n°1 nous utiliserons le capteur BMP280 :  DIGITAL PRESSURE SENSOR : 
Slave adress : 111011X      → le X est déterminé par le câblage du capteur: si SDO est connecté au GND on aura X=0 si SDO est connecté au VDDIO on aura X=1.
                            → en WRITE : 111011X0
                            → en READ : 111011X1              ( le dernier Bit indique si le MASTER veut appelle les SLAVE pour une requête de lecture ou écriture)
Registre d'identification du composant : chip_id[7:0] est à l'adresse 0xD0 est contient la valeur 0x58.
Registre déterminant le mode de fonctionnement du capteur : mode[1:0] est à l'adresse 0xF4 est contient la valeur 11 pour est en normal mode
Registres d'étalonnage du composant: 0xA1 à 0x88
Registres contenant la température (ainsi que le format): temp_xlsb[7:0] est à l'adresse 0xFC,  temp_lsb[7:0] est à l'adresse 0xFB,   temp_msb[7:0] est à l'adresse 0xFA
Registres  contenant la pression (ainsi que le format): press_xlsb[7:0] est à l'adresse 0xF9,  press_lsb[7:0] est à l'adresse 0xF8,   press_msb[7:0] est à l'adresse 0xF7
Fonctions permettant le calcul de la température et de la pression compensées, en format entier 32 bits: bmp280_compensate_T_double (BMP280_S32_t adc_T) pour la temperature et bmp280_compensate_P_double (BMP280_S32_p adc_P) pour la pression.



