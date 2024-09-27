#Ex 1
x=c(19,22,28,24,26,23,23,25)
alpha = 0.05
u0 = 25
n = length(x)
#H0: u = 25
#H1: u != 25
#sigma unknown
#R = (-inf; -t(alpha/2), n-1) U (t(alpha/2), n-1; inf)
t0 = (mean(x) - u0)/sqrt(var(x)) * sqrt(n)
qt(1 - alpha/2, n-1) #t-student distribution with n-1 degrees of freedom

#t0 doesn't belongs to R
#At significance level 0.05, we can't reject H0

#Alternative solution with teaching demos
t.test(x, mu=25, alternative = "two.sided", conf.level = 1-alpha)

#Ex.3
alpha = 0.01
p0 = 0.8
#H0: p <= 0.8
#H1: p > 0.8
n = 450
t = 400
phat = t/n
z0 = (phat - p0)/sqrt(p0*(1-p0)) * sqrt(n)
#R = (zalpha; Inf)
qt(1 - alpha, Inf)
#At significance level 0.01, we reject H0 in favor of H1.
#Thus > 80% of costumers will buy the winter tires

#Ex 4
x=c(59.0, 66.7, 69.7, 57.4, 74.9, 67.7, 78.9, 80.0, 70.8, 81.0)


#Ex 7
x=c(3.5, 3.2, 3.6, 3.0, 3.3, 3.8, 2.5, 3.0, 3.7, 3.9)