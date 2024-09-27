#1
x=c(8, 12, 15, 20, 22, 31)
y=c(74, 129, 182, 220, 260, 410)

#a
plot(x,y)

#b
#correlation coeffitient r = S(xy)/S(x)*S(y)
#covariance S = 1/(n-1) * (SUM(x*y) - n * mean(x) * mean(y))
# + when the valued of feature X increase, then values of feature Y increase too
# - when the valued of feature X increase, then values of feature X decrease too
# 0 - no lenear relationship
# (0; 0.2> - very weak
# (0.2; 0.4> - weak
# (0.4; 0.6> - moderate
# (0.6; 0.8> - strong
# (0.8; 1) - very strong
# 1 - linear
Sxy = cov(x,y)/(sd(x) * sd(y))

#c
# y = b0*x + b1
# b1 = Sxy/Sx - linear regression coefiicient
# b0 = mean(y) - b1*mean(x)
b1 = cov(x,y)/var(x)
b0 = mean(y) - b1 * mean(x)
#If the number of elves helping with packing inreases by 1, the number of wrapped gifts will increase a little over 14

summary(lm(y~x))

#d
#H0: b1 = 0
#H1: b2 != 0
#t0 = r * sqrt(n-2)/sqrt(1-r^2)
#R = (-oo, -t(alpha/2, n-2)) U (t(alpha/2, n-1), oo)
r = cor(x, y)
n = length(x)
t0 = r * sqrt(n-2)/ sqrt(1 - r^2)
qt(1 - 0.05/2, n-2)
#t0 belongs to critical interval
#at significance level alpha = 0.05 we reject H0 in favour of H1.
#Thus the b1 coeffitient is significant

#p-value
2*(1 - pt(17.818, n-2)) #this the output of our summary

#e
curve(b1 * x + b0, add = TRUE)

#f
b1*25 + b0

#g
#R^2 = r^2 = 0.99
# very good fit of linear regression model of the data
# (0.9; 1) - very good fit
# (0.8; 0.9) - good fit
# (0.6; 0.8) - satisfying fit


#2
x=c(2, 4, 5, 7, 10)
y=c(120, 100, 87, 60, 30)

#a
plot(x,y)

#b
cor(x,y) #very strong linear relationship

#c
b1 = cov(x,y)/var(x)
b0 = mean(y) - b1 * mean(x)
summary(lm(x~y))

#d
#p-value = 9.56e-0.5 < alpha
#At significance level alpha = 0.05, we reject H0 in favour of H1
#Thus b1 is significant

#e
curve(b1*x + b0, add = TRUE)

#f
b1*8 + b0

#g
R2 = cor(x,y)^2
#We have very good fit of the linear regression model to the data

#3
x=c(145, 260, 405, 600, 620, 763)
y=c(4.5, 9, 14.4, 17.5, 24, 26.7)
#4
x=seq(5,35,by=5)
y=c(14.1, 13.8, 12.7, 12.3, 11.5, 11.0, 10.3)
#5
x=c(18, 20, 18, 17, 15)
y=c(2, 3, 3, 4, 5)