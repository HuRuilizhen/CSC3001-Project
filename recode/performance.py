from matplotlib import pyplot
import pandas

data = pandas.read_csv("performance.csv")
data.columns = ["K Value", "Accuracy"]

pyplot.plot(data["K Value"], data["Accuracy"])
pyplot.xlabel("K Value")
pyplot.ylabel("Accuracy")
pyplot.title("KNN Performance on MINST")
pyplot.savefig("performance.png")
