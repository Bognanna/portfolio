#Ex.1 - Frequency
alpha = 0.1

#H0: ni = ni0   for every i = 1, 2, 3, 4 (0 means "expected")
#H1: ni =/= ni0 for any i
#x2 = sum((vi-ni0)^2/ni0) //test statistic
#R = (x2(alpha, k-1); oo) //critical interval

n = 300
x = c(122, 85, 76, 17)
per = c(0.38, 0.32, 0.23, 0.07)
ex = per*n

sum((x-ex)^2/ex)#3.29
qchisq(1 - alpha, 3) #6.25
#At significance level alpha = 0.1, we do not reject H0

#chisq.test(observed frequency, probability)
chisq.test(x, p = per)
#p-vale = 0.3485 > alpha = 0.1, therefore we do not reject H0

#degrees of freedom - number of unknown parameters in the distribution


#Ex.2 - Frequency


#Ex 3 - Frequency
b1=c(7,20,10,7,14)
b2=c(20,5,5,13,17)
b3=c(4,16,13,21,4)
b4=c(12,9,16,3,17)

alpha = 0.05
x = b1 + b2 + b3 + b4
ex = rep(0.2, length(b1))

chisq.test(x, p = ex)
#p-value > alpha, therefore we do not reject H0

#Ex 4 - Normal distribution
f=c(7,19,31,17,3,1)

#Ex 5 - Normal distribution
f=c(10,25,35,20,10)
#H0: variable is normally distributed
#H1: ~H0
#(1) Calculate mean and deviation of the sample
#.
#x the middle of the interval
x_dot = c(1, 3, 5, 7, 9)
n = 100
mean_x = sum(x_dot * f)/n
var_x = 1/(n-1) * (sum(x_dot^2 * f) - n * mean_x^2)
sd_x = sqrt(var_x)
sd_x

#(2) Calculate area of intervals under the plot
a1 = pnorm(2, mean_x, sd_x)
a2 = pnorm(4, mean_x, sd_x) - pnorm(2, mean_x, sd_x)
a3 = pnorm(6, mean_x, sd_x) - pnorm(4, mean_x, sd_x)
a4 = pnorm(8, mean_x, sd_x) - pnorm(6, mean_x, sd_x)
a5 = 1 - pnorm(8, mean_x, sd_x) #EXTRA POINTS IF TILL THE END OF THE WEEK IT WILL BE AUTOMIZED
a = c(a1, a2, a3, a4, a5)

chisq.test(f, p=a)
#Very high p-value, so we are almost sure, that it is normally distributed
  
#Ex 6 - Independence
u=c(15,12,8)
s=c(8,15,9)
r=c(6,8,7)
#H0: pij = pi0    p0j for all i,j
#H1: ~H1
#x2 = sum(sum(((nij-Eij)^2)/Eij))
#Eij = ni0 * n0j/n
#R = (x2(alpha, (kx - 1)*(ky - 1)); oo)

N = rbind(u, s, r)
E = matrix(rep(0, 9), ncol = 3)
E

for(i in 1:3){
  for(j in 1:3){
    E[i,j] = sum(N[i,]) * sum(N[,j])/sum(N)
  }
}

E

sum((N-E)^2/E)
qchisq(1 - alpha, (3-1)*(3 - 1))
#We do not reject H0

chisq.test(N) #Another solution

#Ex 7 - Independence
y=c(10,7,4)
n=c(90,93,96)