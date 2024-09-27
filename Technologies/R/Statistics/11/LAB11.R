#Ex 1
tv=c(12, 10, 15, 9, 12, 18, 14, 8, 9, 20)
radio=c(15, 17, 6, 6, 4, 9, 1, 4, 3, 13)
income=c(70, 77, 81, 70, 66, 82, 68, 61, 65, 85)

#multiple regression
#y = b2 * xtv + b1 * xr + b0

#a
plot(tv,income)
plot(radio,income)

#b
cor(tv, income) #very strong correlation coefficient
#If the tv expenditure increases then the weekly income increases too,
#This relation is linearly very strong

cor(radio, income) #moderate correlation coefficient
#If the radio expenditure increases then the weekly income increases too,
#This relation is linearly moderate

#c
y = income
x = cbind(rep(1,length(income)), radio, tv)
b = solve(t(x) %*% x) %*% t(x) %*% y
b #y = 1.46*xtv + 0.58*xr + 49.41
# 0.58 -> If radio expenditure increases by 1000 Euro, then the weekly income increases by 580 Euro
# 1.46 -> If tv expenditure increases by 1000 Euro, then the weekly income increases by 1460 Euro
# 49.41 -> Weekly income without any adverts
summary(lm(income~tv+radio))

#d
#radio
#H0: b1 = 0
#H1: b1 != 0

#tv
#H0: b2 = 0
#H1: b2 != 0

#p-value (from summary) = 0.06 > alpha
#at significance level 0.05 we do not reject H0

#p-value = 0.004 < alpha
#we reject H0 in favor of H1. Thus b2 is significant

#e
xtv = 16
xr = 6
predict(lm(income~tv+radio), data.frame(tv = xtv, radio = xr))

#f
#From summary
#Multiple R-squared: 0.799
#The fit of multiple regression to data is good/moderate


#Ex 3
h=c(57.5, 52.8, 61.3, 67.0, 53.6, 62.7, 56.3, 68)
a=c(77, 68, 73, 86, 66, 81, 75, 93)
bh=c(45.4, 46.8, 46.3, 49.0, 43.8, 45.9, 56.1, 56.1)
bw=c(2.7, 2.2, 4.3, 5.1, 3.3, 4.5, 2.6, 4.4)

#Ex 4
x=c(5, 7, 11, 14, 20, 24, 30)
y=c(45, 53, 82, 143, 332, 635, 901)

#Ex 5
x=c(1, 4, 7, 8, 10, 13, 18, 22, 25, 28)
y=c(35, 45, 59, 77, 62, 50, 39, 47, 54, 71)

#a
plot(x,y)

#b
cor(x,y) #weak correlation coefficient

#c
X = cbind(rep(1, length(x)), x, x^2, x^3)
b = solve(t(X) %*% X) %*% t(X) %*% y
b # y=22.25 + 11.38 * x - 0.96 * x^2 + 0.022 * x^3

summary(lm(y~x + I(x^2) + I(x^3)))

#d
summary(lm(y~x + I(x^2)))
summary(lm(y~x + I(x^2) + I(x^3))) #x, x^2, x^3 are significant, because their p-valueas are smaller than 0.005
summary(lm(y~x + I(x^2) + I(x^3) + I(x^4)))

#e
curve(22.24553 + 11.28161 * x - 0.96805 * x^2 + 0.02215 * x^3, add = TRUE)

#f
predict(lm(y~x + I(x^2) + I(x^3)), data.frame(x = 15))
predict(lm(y~x + I(x^2) + I(x^3)), data.frame(x = 48))
#model of this polynomial is proper for values up to 28

#g
#multiple r-squared: 0.7659

#Statistic is not:
#a) sum of random variables
#b) multiplication of random varibles
#c) population mean
#Odp.: c

#What we can find on boxplot:
#Odp.: min, max, Q1, Q2, Q3

#The sample:
#a) Is finite of population
#b) Is infinite of population
#c) At least contains 10
#Odp.: a

#When we have H0: u = 10 and H1: u != 10. We are testing:
#a) The population mean
#b) The significance level
#Odp. : a

#What are the dispersion measures:
#variance, sd, interquartile range, range, /something more/

#The alpha is probability of type:
#a) 1
#b) 2
#Odp.: a

#The set of values of test statistics for which we just reject H0, we call:
#a) the significance level
#b) critical interval
#Odp.: b

#Ex6
x=c(5, 15, 30, 40, 55, 65, 80, 90)
y=c(130, 98, 78, 65, 58, 73, 104, 147)