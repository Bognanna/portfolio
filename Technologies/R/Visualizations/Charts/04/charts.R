h_data <- read.csv("wyn1_3.csv", header = TRUE, sep = ",")
ggplot(data = h_data, aes(x = n, y = time, color = factor(sat))) + geom_line() + ggtitle("Hamiltonian Cycle") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

h_mean <- aggregate(h_data$time, by = list(h_data$n, h_data$sat), max) 
colnames(h_mean) <- c("n", "sat", "time")

h_data %>%
  filter(sat > 0.3) %>%
  ggplot(aes(x = n, y = time, color = factor(sat))) + geom_line() + ggtitle("Hamiltonian Cycle") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

h_data <- read.csv("ec1.csv", header = TRUE, sep = ",")
ggplot(data = h_data, aes(x = n, y = time, color = factor(sat))) + geom_line() + ggtitle("Eulerian Cycle") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)
