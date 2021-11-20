# TP7_Erkan_Enzo

# Membres

|  Nom|Prénom  |Numéro étudiant  |
|--|--|--|
|CECILLON  |Enzo  |11805901  |
| AKSOY | Erkan |1191102 |


## Presentation
---
Ce projet est réalisé dans le cadre de l'UE LIFAP6.


## Explications Arbre Rouge et Noir
---

### Sources
---

[Procédure affichage Arbre](https://forge.univ-lyon1.fr/lifap6/tp-arbretas-etu/-/blob/master/Code/arbre.cpp)

[Rappel sur les arbres](https://fr.wikipedia.org/wiki/Arbre_bicolore)

[GeeksForGeeks](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)

[Rotation Arbre binaire](https://fr.wikipedia.org/wiki/Rotation_d%27un_arbre_binaire_de_recherche)

[Arbre Rouge et Noir](https://fr.wikipedia.org/wiki/Arbre_bicolore)

[Print 2D Tree](https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/)
### Exemple d'abre Rouge et Noir
---
![Image Arbre Rouge et noir](https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Red-black_tree_example.svg/720px-Red-black_tree_example.svg.png)

> La hauteur noire de cet arbre est de 2.

### **Propriétés d'un Arbre Rouge et Noir**
---

|  | Description |
| ----------- | ----------- |
| 1 | La racine est Noir. |
| 2 | Un Noeud est soit rouge et Noir. |
| 3 | Les enfants d'un noeud rouge sont noirs. |
| 4 | Les enfants sont d'autres noeuds ou des feuilles => NULL. Leur couleur est toujours Noire et rentre en compte dans le calcul de la hauteur Noire.|
| 5 | Le nombre de noeud Noire en allant de la racine à la feuille NULL est appelé hauteur de l'abre (on ne compte pas la valeur de la racine dans la hauteur). Il est le même pour toutes les branches (cf image ci-dessus) |


> **Rq Propriété 5** : On notera que l'alternance entre les noeuds de couleur rouge et noirs nous ramène toujours à la même hauteur peu importe la branche ce qui permet d'optimiser les opérations de recherche, insertion ...

### Rotation d'un Arbre
---

[Source pour algorithme](https://fr.wikipedia.org/wiki/Rotation_d%27un_arbre_binaire_de_recherche)

**Algortihme pour la rotation droite :**
```c++
// Pivot = le nouveau Parent du noeud que l'on va tourner dont l'actuel noeud = parent.
Pivot = parent->fg 
// Le nouveau fg du parent est le fils droit du pivot pour respecter les règles de l'abr.
parent->fg = Pivot->fd
// On change le lien vers le fd avec celui du parent.
Pivot->fd = parent
// On change l'adresse du parent avec celle du noveau parent qui n'est autre que le pivot.
parent = Pivot. 
```
[Explication vidéo](https://www.youtube.com/watch?v=q4fnJZr8ztY)

**Algotithme pour la rotation gauche**
```c++
// Symétrie par rapport à la rotation gauche.
Pivot = parent->fd
parent->fd = Pivot->fg // on prend son pivot gauche sinon si on prend le droit il va être plus grand que le parent donc désequilibre.
Pivot->fg = parent // Comme le pivot va passer racine on fait pointer le fg (car le parent est plus petit que le pivot)
parent = Pivot.
```
On utilisera la rotation lorsque l'on ajoutera un nouveau noeud qui va désiquilbré la hauteur de notre Arbre. 
(Si on a une différence trop importante l'abre deviendra dégénéré et la complexité va augmenter ce que l'on veut pas).
### Insertion dans un Arbre Rouge Noir.
---
Il y a en tous 4 cas à gérer.


|  | Description |
| ----------- | ----------- |
| 1 | Mon Parent est NULL => Je suis Noire (nouveau noeud). |
| 2 | Mon Parent est Noire, comme j'ajoute un noeud qui est rouge par défaut je ne fais rien. |
| 3 | Mon Parent et mon Oncle sont rouges => je colore les deux en noirs. Je dois colorier le grand père en Rouge et regarder pour les noeuds plus haut si on est dans le même cas. (appel récursif sur les noeuds plus haut) |
| 4 | Mon Parent est Rouge mais mon Oncle est Noir, on va devoir effectuer des rotations à partir du Parent. (Pour savoir quelle/s rotation/s effectuer cf les quotes ci-dessous) |
| 5 | [📢️] Ce cas s'applique que si on était dans le cas 4] On doit faire une rotation autour du Grand-père. Le Parent du sous arbre doit passer noir et le Grand-père qui a tourner devient Rouge.|
---
> | 4.1 | Si le noeud introduit est le Fils Droit du Fils Gauche du Grand-père => je fais une rotation Gauche sur le Parent et le fils gauche du Noeud (qui est le parent mtn) devient l'ancien Parent. 


> | 4.2 | Si je suis le Fils Gauche du Fils Droit du Grand-père => je fais une rotation à Droite sur le Parent et le fils droit du Noeud devient l'ancien Parent.

> | 5.1 | Si le noeud inséré après la rotation est à gauche du noeud le plus haut dans le sous arbre (parent->gauche) => Rotation Droite.

> | 5.2 | On fait une rotation gauche si il est à droite.


### Affichage d'un Arbre
---
**Algorithme**
```
Si Noeud non NULL
    Appel Récursif sur la partie Droite.
    Retour ligne.
    On met un certain nombre d'espace en fonction de la profondeur à laquelle on est.
    On affiche l'élément.
    Appel Récursif sur la partie gauche.
Fin
```
---
**Explication**
> Dans l'idée, on fait l'inverse du parcours infixe (gauche, cle ,droite)
- On affiche le noeud le plus à droite sur la première ligne.
- On affiche le noeud le plus à gauche sur la dernière ligne.
- A chaque fois que l'on atteint le noeud NULL et que l'on sort de l'appel récursif on revient à "l'espacement-1" puis on ajoute un certains nombre de caractère vide sur la ligne qui correspond à la profondeur du noeud.
- La valeur du noeud sera affiché avec sa couleur.
## Code source de l'Arbre Rouge et Noir
---
[Arbre_RN.cpp](https://forge.univ-lyon1.fr/p1805901/tp7_erkan_enzo/-/blob/main/src/arbre_ARN.cpp)

## Code source Arbre binaire 
---
[Arbre Binaire de recherche](https://forge.univ-lyon1.fr/p1805901/tp7_erkan_enzo/-/blob/main/src/arbre.cpp)