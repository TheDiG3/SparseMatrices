SparseMatrices - John Leblanc & Simone Di Gravio
==============

Summary
---

This program was developed in order to be able to provide an efficient representation of a **sparse matrix**, that is, a matrix for which not all elements actually are a non-zero value. In order to **save memory** we can just save non-zero elements in a particular kind of structure: the **orthogonal list**.
The typical layout of an orthogonal list consists of a **head node** indicating how many columns and rows there are in the matrix, with links to the relative row and column head nodes (one for each row/column in the matrix). This makes traversing, adding and deleting any node in the list simple and efficient.
The program focuses in particular on the **addition of two sparse matrices** expressed as orthogonal lists.

Implementation
---

The two fundamental class methods of the program are **"insert"** and the **"+ operator"**.
After the constructor has created the main head node and the row/column head nodes we can start inserting values inside the orthogonal list.

The way **insert** works is simply as follows:
- Navigate to the node (row, column) specified by the parameters.
- If the node is not present a new node is created, the value saved inside the node data field and the references for the list get updated.
- Else the value is just updated.

The way the **+ operator** works:
- It relies on the method **getElementData** which returns the integer associated with a certain row and column node of the matrix. Note that **getElementData** returns 0 if the node is not found and throws if the indexes are out of bounds.
- Loops the two indexes (row and column) and sums the integers obtained from **getElementData** of the two summed matrices.
