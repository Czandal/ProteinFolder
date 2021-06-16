# ProteinFolder
ProteinFolder is an implementation of technique presented in the article below:
https://www.ncbi.nlm.nih.gov/pmc/articles/PMC5172541/
Used technologies: C++ and SFML.
Used technique: Branch and bound.
Input is a string of letters 'h' and 'p' (is not case sensitive). H stands for hydrophobic and P stands for polar. To control computation time one needs to adjust P1 and P2 (they represent how likely it is for the branch to be ommited).
Output is energy of the system (the lower the better).
