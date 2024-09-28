percent = c(4.8, 4.7, 4.5, 4.4, 4.6, 4.4, 4.4, 4.5, 4.5, 4.5, 4.6, 5.0, 5.3, 5.6, 6.0, 6.2, 6.5, 6.7, 7.0)
years = seq(2009, 2027, 1)

col_po = rep(c("blue"),7)
col_pis = rep(c("green"),7)
col_pre = rep(c("gray"),5)
col_all = c(col_po, col_pis, col_pre)

barplot(percent, names.arg = years, ylab = "Percent of the GBP", main = "Expenses for the health service as the % of the GBP", col = col_all)
