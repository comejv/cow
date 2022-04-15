# PROJET COW

EXECUTION :
Pour exécuter cow, téléchargez le fichier binary nommé main et lancez le à partir d'une invite de commande.

OPTIONS POSSIBLES :
Notez qu'une option est qualifiée de "suffisante" si son utilisation seule permet au programme de s'éxécuter normalement. Toutes les options suivantes seront ignorées.
-y : permet de choisir le charactère utilisé
-p : permet de choisir le charactère utilisé
-t : (suffisante) permet de choisir le texte de la bulle de la vache ("Bonjour !" par défaut).
-d : (suffisante) permet de jouer à un jeu de devinette avec la vache. Pensez à un nombre et guidez la vache pour qu'elle le trouve.
-v : (suffisante) permet de préciser un type de vache à afficher. Voir "Modèles spéciaux" pour les choix possibles.
-h : (suffisante) affiche le manuel du programme (mais vous le saviez, puisque vous êtes là).

MODELES SPECIAUX :
portrait : vous avez toujours voulu embellir le mur de votre salon, et la vache a gracieuseument proposé d'y mettre sa tête en gros plan. Voilà la photo qu'elle vous donne.
assise : la vache vous a marché sur le pied et vous n'êtes pas content. Vous la faite s'assoir pour la réprimander.

EXEMPLES :
./cow                       -> vache par défaut
./cow -y:^                  -> vache par défaut avec ^ à la place des yeux
./cow -y:x -p:y             -> vache par défaut avec x pour yeux et y pour pis
./cow -s portrait           -> vache spéciale portrait
./cow -t "Je suis morte !"  -> vache qui dit "Je suis morte !"
./cow -d                    -> lance le jeu de devinette
./cow -h -s assise          -> affiche l'aide seulement car l'option -h est suffisante