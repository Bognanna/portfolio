#Ex.1
n1 = 8
n2 = 21
mean1 = 29.13
mean2 = 33.14
sd1 = 4.59
sd2 = 7.44
alpha = 0.02

#We have to test 2 variances if they are homogenous
#H0: sigma1 = sigma2
#H1: sigma1 != sigma2

#F0 = (Sd1 ^ 2)/(Sd2 ^ 2)
#R = (0; 1/F(alpha/2, n1 - 1, n2 - 1)) U (F(alpha/2, n1 - 1, n2 - 1), oo)

F0 = (sd1*sd1)/(sd2*sd2)
R1 = 1/qf((1-alpha/2), n2 - 1, n1 - 1)
R2 = qf((1-alpha/2), n2 - 1, n1 - 1)

#At significance level alpha = 0.02, we do not reject H0,
#but we have to make some assumptions

#Assumption: homogenity of variance (sigma1^2 = sigma2^2)
#H0: u1 = u2
#H1: u1 != u2

#R = (-oo; -t(alpha/2, n1+n2-2)) U (t(alpha/2, n1+n2-2; oo))
t0 = (mean1 - mean2)/ sqrt(((n1 - 1)*sd1*sd1 + (n2 - 1)*sd2*sd2) * (n1 + n2)/((n1+n2-2)*n1*n2))

R1 = qt(1 - alpha/2, n1 + n2 - 2)
#t0 doesnt belongs to R, so we don't know anything

#Ex 2 
x=c(6.01, 5.48, 5.92, 6.12, 5.76, 5.88)
y=c(5.32, 5.66, 5.87, 5.99, 5.59)
alpha = 0.02
n1 = length(x)
n2 = length(y)
mean1 = mean(x)
mean2 = mean(y)
var1 = var(x)
var2 = var(y)

#test for 2 variances

#H0: sigma1 ^ 2 >= sigma2 ^ 2
#H1: sigma1 ^ 2 < sigma2 ^ 2

F0 = var1/var2
R1 = 1/qf(1 - alpha, n2-1, n1-1)
#At significance level 0.02 we do not reject H0

var.test(x, y, alternative = "less", conf.level = 1 - alpha)

#Ex.3
#H0: p1 <= p2
#H1: p1 > p2

#R = (t(aplha, oo); oo)
T1 = 250
n1 = 300
T2 = 135
n2 = 220
alpha = 0.01

#test for 2 fractions
p1 = T1/n1
p2 = T2/n2
p = (T1 + T2)/(n1 + n2)

z0 = (p1 - p2)/(sqrt((1 - p)*p) * sqrt((1/n1 + 1/n2)))
qt(1 - alpha, Inf)

#At significance level alpha = 0.01, we reject H0 in favor of H1
#The percentage of people susceptible to the vitamin is greater
#in the 1. group

#We can also use prop.test():
prop.test(c(T1,T2), c(n1, n2), alternative = "greater", conf.level = 1-alpha)

#Ex 4
x=c(8.9, 9.5, 9.0, 9.4, 9.9, 8.7, 9.1, 9.1, 9.3, 8.9, 9.3)
y=c(9.6, 8.5, 8.9, 9.4, 9.5, 9.3, 8.4, 9.0, 9.7, 9.2, 9.0, 9.1, 8.9, 9.4)

#Ex 5
x=c(4.6, 3.9, 4.3, 4.5, 4.4)
y=c(5.1, 4.6, 6.5, 4.1, 4.1, 3.9)

#Ex 7
x=c(41, 40, 34, 62, 39, 54, 28)
y=c(30, 51, 46, 27, 31, 29, 35)

var.test(x, y, alernative = "two.sided", conf.level = 0.99)

#H0: sigma1 ^ 2 = sigma2 ^ 2
#H1: sigma1 ^ 2 != sigma2 ^ 2

#At significance level alpha = 0.01, we do not reject H0
#Assumption: homogeonity of variance
#H0: u1 = u2
#H1: u1 != u2

#we do not know anything about sd, so we use T test

t.test(x,y, var.equal = TRUE, alternative = "two.sided", conf.level =  0.99)

#p-value is greater, so we can't reject anything
