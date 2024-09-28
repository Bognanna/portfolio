ex4_rand <- read.csv("p_rand.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_rand, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("Random") +
theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_cons <- read.csv("p_cons.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_cons, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("Constant") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_decr <- read.csv("p_decr.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_decr, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("Decreasing") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_incr <- read.csv("p_incr.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_incr, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("Increasing") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_a <- read.csv("p_a.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_a, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("A-shape") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_v <- read.csv("p_v.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_v, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("V-shape") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)