ex4_rand <- read.csv("ol.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_rand, aes(x = no_elements, y = time, color = factor(operation))) + geom_line() + ggtitle("Random") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_bst <- read.csv("bst.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_bst, aes(x = X0, y = X0.1, color = factor(append))) + geom_line() + ggtitle("Random") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_bbst <- read.csv("bbst.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_bbst, aes(x = X0, y = X0.1, color = factor(append))) + geom_line() + ggtitle("Random") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex4_all <- read.csv("colective.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex4_all, aes(x = no_elements, y = time, )) + geom_line() + ggtitle("Random") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

append <- ex4_all[c(seq(1,351,3)),c(1,2,4)]
search <- ex4_all[c(seq(2,351,3)),c(1,2,4)]
delete <- ex4_all[c(seq(3,351,3)),c(1,2,4)]

ggplot(data = append, aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average insertion time: BBST vs. BST vs. OL") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ggplot(data = search, aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average search time: BBST vs. BST vs. OL") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ggplot(data = delete, aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average delete time: BBST vs. BST vs. OL") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

append %>%
  filter(data_structure != "OL") %>%
  ggplot(aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average insertion time: BBST vs. BST") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

search %>%
  filter(data_structure != "OL") %>%
  ggplot(aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average search time: BBST vs. BST") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

delete %>%
  filter(data_structure != "OL") %>%
  ggplot(aes(x = no_elements, y = time, color = factor(data_structure))) + geom_line() + ggtitle("Average delete time: BBST vs. BST") +
  theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

