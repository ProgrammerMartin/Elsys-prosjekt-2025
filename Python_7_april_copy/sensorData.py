import numpy as np
from configVariabler import t, toll

# Variabler for data
time = np.linspace(-toll * t, 0, toll)

# Lister for akselerasjon, hastighet og posisjon
adata = np.zeros(toll)
vdata = np.zeros((toll, 3))
vdata_abs = np.zeros(toll)
sdata = np.zeros((toll, 3))

# Initialiseringsliste for retningsvektoren
cv = np.array([1, 1, 0])
