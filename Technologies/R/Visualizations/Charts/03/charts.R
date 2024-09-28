results = read.csv("wyn.csv", sep = ",")

ggplot(data = results, aes(x = number.of.vertices, y = time, color = factor(graph.representation))) + geom_line() + 
  ggtitle("Comparision of time needed to check existence of an edge") +
  theme(legend.text = element_text(size = 14), 
        legend.title = element_text(size = 12)) + 
  labs(color='Graph representation')+
  theme_gray(base_size = 18)

results2 = read.csv("wyn2.csv", sep = ",")

ggplot(data = results2, aes(x = n, y = time)) + geom_line() + 
  ggtitle("Topological sort of DAG") +
  theme(legend.text = element_text(size = 14), 
        legend.title = element_text(size = 12)) + 
  labs(color='Graph representation')+
  theme_gray(base_size = 18)
