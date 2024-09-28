ex3 <- read.csv("bs_cs_hs_shs.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex3, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("BS vs. CS vs. HS vs. SHS") +
theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)

ex3 <- read.csv("cs_hs_shs.csv", dec = ".", head = TRUE, sep = ",")
ggplot(data = ex3, aes(x = n, y = time, color = factor(sort))) + geom_line() + ggtitle("CS vs. HS vs. SHS") +
theme(legend.text = element_text(size = 14), legend.title = element_text(size = 12)) + theme_gray(base_size = 18)
