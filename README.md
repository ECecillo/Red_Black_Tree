# TP7_Erkan_Enzo

# Membres

|  Nom|Prénom  |Numéro étudiant  |
|--|--|--|
|CECILLON  |Enzo  |11805901  |
| AKSOY | Erkan | ... |


## Presentation
---
Ce projet est réalisé dans le cadre de l'UE LIFAP6.


## Explications Arbre Rouge et Noir
---

### Sources
---
[Source Wikipedia](https://fr.wikipedia.org/wiki/Arbre_bicolore)

[GeeksForGeeks](https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/)


[Rotation Arbre binaire](https://fr.wikipedia.org/wiki/Rotation_d%27un_arbre_binaire_de_recherche)
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

---
> **Rq Propriété 5** : On notera que l'alternance entre les noeuds de couleur rouge et noirs nous ramène toujours à la même hauteur peu importe la branche ce qui permet d'optimiser les opérations de recherche, insertion ...

