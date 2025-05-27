def rotate_2d_matrix(matrix):
    m = len(matrix)

    # Étape 1 : Transposer la matrice
    for i in range(m):
        for j in range(i + 1, m):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Étape 2 : Inverser chaque ligne
    for row in matrix:
        row.reverse()
