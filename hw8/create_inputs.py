filename = "part1"

inputs = []
f = open(filename)
for line in f:
    print line
    if not line or line.isspace() or line.startswith("#"):
        continue
    else:
        after_description = line.find('"', 2) + 1
        tokens = line[after_description:].split()
        print tokens
        i, j, k, result = tokens
        inputs.append((i, j, k))

for (t, vals) in enumerate(inputs):
    i, j, k = vals
    fname = "input_{:02}".format(t+1)
    f = open(fname, 'w')
    f.write("{} {} {}".format(i, j, k))
    f.close()
