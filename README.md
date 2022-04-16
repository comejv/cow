<div id='top'></div>

# PROJET COW
Projet final d'INF 203 de Côme VINCENT.

<details>
  <summary>Sommaire</summary>
  <ol>
    <li><a href="#execution">Execution</a></li>
    <li><a href="#modeles-speciaux">Modèles spéciaux</a></li>
    <li><a href="#exemples">Exemples</a></li>
  </ol>
</details>
<div id="execution">

## Execution :
Pour exécuter cow, téléchargez le fichier binary nommé main et lancez le à partir d'une invite de commande.

OPTIONS POSSIBLES :
Notez qu'une option est qualifiée de "suffisante" si son utilisation seule permet au programme de s'éxécuter normalement. Toutes les options suivantes seront ignorées.

* -y : permet de choisir le charactère utilisé
* -p : permet de choisir le charactère utilisé
* -t : (suffisante) permet de choisir le texte de la bulle de la vache ("Bonjour !" par défaut).
* -d : (suffisante) permet de jouer à un jeu de devinette avec la vache. Pensez à un nombre et guidez la vache pour qu'elle le trouve.
* -v : (suffisante) permet de préciser un type de vache à afficher. Voir "Modèles spéciaux" pour les choix possibles.
* -h : (suffisante) affiche le manuel du programme (mais vous le saviez, puisque vous êtes là).
</div>
<div id="modeles-speciaux">

## Modèles spéciaux :

* portrait : vous avez toujours voulu embellir le mur de votre salon, et la vache a gracieuseument proposé d'y mettre sa tête en gros plan. Voilà la photo qu'elle vous donne. Art par Joan Stark.
* assise : la vache vous a marché sur le pied et vous n'êtes pas content. Vous la faite s'assoir pour la réprimander. Art par Joan Stark.
* sauvage : elle brise les attentes sociétales. Art par mic & dwb.
* canadienne : très polie ! Art par Veronica Karlsson.
</div>
<div id="exemples">

## Exemples :

* ```sh ./cow```                       -> vache par défaut
* ```sh ./cow -y:^```                  -> vache par défaut avec ^ à la place des yeux
* ```sh ./cow -y:x -p:y```             -> vache par défaut avec x pour yeux et y pour pis
* ```sh ./cow -s portrait```           -> vache spéciale portrait
* ```sh ./cow -t "Je suis morte !"```  -> vache qui dit "Je suis morte !"
* ```sh ./cow -d```                    -> lance le jeu de devinette
* ```sh ./cow -h -s assise```          -> affiche l'aide seulement car l'option -h est suffisante
</div>
<p align="right">(<a href="#top">back to top</a>)</p>