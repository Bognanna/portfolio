#Ex 1
x=c(5.9, 4.4, 5.4, 3.8, 4.0, 4.2, 3.4, 3.6, 4.6, 6.5, 5.6, 4.8)
#u0 = 4
#H0: u <= 4
#H1: u > 4
m = mean(x)
n = length(x)
s = sd(x)
u0 = 4
t0 = (m - u0)/s*sqrt(n)
qt(1-0.05, n-1)
#At significance level alpha = 0.05, we reject H0 in favor of H1. Hence it is good to build the wind farm in area of Dar³owo
#(t0 belongs to R, p-value < alpha)

#At significance level alpha = 0.05, we do not reject H0
#(t0 doesn't belong to R, p-value > alpha)

t.test(x, mu=u0, alternative = "greater", conf.level = 0.95)


#Ex 2
x=c(1.5, 1.8, 1.5, 1.7, 1.6, 1.6, 1.8, 1.6, 1.7, 1.6)
#H0: sigma^2 >= 0.02
#H1: sigma^2 < 0.02
n = length(x)
s2 = var(x)
sigma02 = 0.02
chi0 = (n-1)*s2/sigma02
#package teachingdemos
qchisq(0.05, n-1)
sigma.test(x, sigmasq = 0.02, alternative = "less", conf.level = 1-alpha)

#Ex 3
x=c(17.93,	18.52,	19.66,	14.30,	17.52,	20.76,	20.26,
    19.82,	21.40,	16.54,	18.64,	17.62,	20.79,	19.14,
    16.74,	14.93,	18.56,	15.43,	15.19,	21.05,	20.79)

#Ex 4
#H0: p >= 0.02
#H1: p < 0.02
T = 16
n = 1200
p0 = 0.02
phat = T/n
z0 = (phat - p0)/sqrt((1-p0)*p0)*sqrt(n)
qt(0.95, Inf)
prop.test(T, n, p=p0, alternative = "less", conf.level = 0.95)

#Ex.7
#H0: u = 870
#H1: u != 870

u0 = 870
sigma = 5
x = c(862, 870, 876, 866, 871)
z0 = (mean(x) - u0)/sigma * sqrt(length(x))
#R = (-inf; -z(alpha/2)) U (z(alpha/2); inf)
alpha = 0.05
#Solution 1
qt(1 - alpha/2, Inf)
#Solution 2
qnorm(1 - alpha/2, 0, 1)
#z0 doesn't belongs to R
#At significance level alpha = 0.05, we do not reject H0

#PACKAGE TEACHINGDEMOS
z.test(x, mu = u0, stdev = sigma, alternative = "two.sided", conf.level = 1-alpha)
#pvalue = 0.6547 > alpha, the same interpretation

#Ex 6
x=c(3.0, 3.3, 3.1, 3.2, 3.2, 3.0, 2.9, 3.1)

#Ex 8
x=c(6.01, 5.48, 5.92, 6.12, 5.76, 5.88)
y=c(5.32, 5.66, 5.87, 5.99, 5.59)

#Ex 10
x=c(8.9, 9.5, 9.0, 9.4, 9.9, 8.7, 9.1, 9.1, 9.3, 8.9, 9.3)
y=c(9.6, 8.5, 8.9, 9.4, 9.5, 9.3, 8.4, 9.0, 9.7, 9.2, 9.0, 9.1, 8.9, 9.4)