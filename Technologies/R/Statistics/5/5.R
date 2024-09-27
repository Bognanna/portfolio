#Ex.1
  #a population - all diamonds produced by the new sintetic methods
  #sample - 6 diamonds
  #test variable - the wight of diamonds
#b
d1 = c(0.46, 0.61, 0.52, 0.48, 0.57, 0.54)
m1 = mean(d1)
s1 = sd(d1)
#c
#standard deviation is unknown
#alpha = 0.95 - confidence level
#1-alpha = 0.05 - significance level
#t(alpha/2, n-1) = qt(1-alpha/2, n-1), qt- quantile
n1 = length(d1)
t1 = qt(1-0.05/2,n1 - 1)
sd(d1)
m1 - t1*s1/sqrt(n1)
m1 + t1*s1/sqrt(n1)
#With 95% confidence we can say, that the confidence interval (0.47, 0.59) [carats]
#Covers what unknown mean of diamond's weight
t.test(d1, conf.level = 0.95)
#d
t.test(d1, conf.level = 0.98) #the convidence interval is bigger
#e
chi11 = qchisq(1-0.05/2, n1-1)
chi21 = qchisq(0.05/2, n1-1)
(n1-1)*s1^2/chi11
(n1-1)*s1^2/chi21

#install.packages("TeachingDemos")
#library(TeachingDemos)
#sigma.test(d1, conf.level = 0.95)

#Ex.2
n2 = 365
m2 = 102
s2 = 9
alpha2 = 0.02
z2 = qt(1 - alpha2/2, Inf)
m2 - z2*s2/sqrt(n2)
m2 + z2*s2/sqrt(n2)

#Ex.3
x3 = c(4.28, 3.3, 4.22, 2.77, 2.75, 2.93, 3.86, 3.05, 4.12, 2.88, 3.94, 4.99, 2.08, 4.35, 2.7, 4.09, 2.81, 2.82)

#Ex.5
sigma5 = 15
n5 = 10
m5 = 600
alpha5 = 0.1
z5 = qt(1-alpha5/2, Inf)
m5 - z5*sigma5/sqrt(n5)
m5 + z5*sigma5/sqrt(n5)

#Ex.9
x9 = c(5,7,5,6,9,8,11)
#install.packages("BSDA")
#library(BSDA)
z.tets(x9, sigma.x9 = sigma, conf.level = 1-alpha)
z.test(x, stdev = 2, conf.level = 0.95)

#Ex. 10
T = 330
n = 500
phat = T/n
alpha = 0.05
z = qt(1 - alpha/2, Inf)
phat - z*sqrt(phat*(1-phat)/n)
phat + z*sqrt(phat*(1-phat)/n)
#With 95% confidence we can say, that confidence interval (0.62; 0.7) covers the unknown percentage of people that are satisfied in UE.
prop.test(T, n, conf.level = 1 - alpha) #another way of solution
#HW 11

#EXAM

