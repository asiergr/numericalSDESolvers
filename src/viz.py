import matplotlib.pyplot as plt

out = []
with open("./../results.txt", "r") as res:
    points = res.read().split("\n")
    for point in points:
        if point != "":
            out.append(float(point))

plt.plot(out)
plt.show()