#1
w=c(4.07, 4.09, 4.06, 4.09, 4.08)
c=c(4.06,	4.08,	4.07,	4.07,	4.07)
g=c(4.08,	4.09,	4.08,	4.10,	4.09)

#a
#H0: sigma1 ^ 2 = sigma2 ^ 2 = sigma3 ^ 2
#H1: ~H0

#bartlett test(values ~ names)
values = c(w, c, g)
names = rep(c("w","c", "g"), each = 5)

bartlett.test(values~names)
#p-value = 0.4717 > alpha = 0.05
#At significance level alpha = 0.05, we don't reject H0 

#b
#aov - analizis of variance
#summary(aov(values~names))

a = aov(values~names)
summary(a)                                                                                                                                                                                                                                                                                                                                                                                                                                  
#p-value = 0.0413 < alpha
#At significance level alpha = 0.05, we reject H0 in favour of H1.
#Thus at least one mean ground temperature is different.

#c
#H0: U(w) = u(g)    H0: uc = ug
#H1: u(w) != u(g)   H1: uc != ug
names = factor(names)
a = aov(values~names)
TukeyHSD(a)
#p-value = 0.28 > alpha: we don't reject
#p-value = 0.03 < alpha: we reject

#2
l=c(28,	26,	29,	30,	28,	31,	26,	32,	25,	29)
m=c(30, 29, 30, 30,	28,	32,	29,	32,	28,	30)
s=c(31,	29,	33,	33,	29,	33,	28,	32,	27,	32)
h=c(29,	27,	30,	31,	27,	32,	27,	32,	27, 30)

values = c(l,m,s,h)
names = rep(c("l", "m", "s", "h"), each = length(l))
bartlett.test(values~names)

summary(aov(values~names))

names = factor(names)
TukeyHSD(aov(values~names))

#3
m1=c(6.5, 7.8, 6.9, 6.4)
m2=c(7.2, 8.5, 7.3, 7.0)
m3=c(7.2, 7.5, 7.1, 7.5)
m4=c(7.1, 7.0, 7.1, 7.2)
m5=c(7.2, 6.6, 7.4, 7.5)

#4
non=c(69, 52, 71, 58, 59, 65)
sli=c(91, 72, 81, 67, 95, 84)
med=c(55, 60, 78, 58, 62, 66)
much=c(66, 81, 70, 77, 57, 79)

values = c(non, sli, med, much)
names = rep(c("non", "sli", "med", "much"), each = length(non))

bartlett.test(values~names)
#We assume that variances are equal

summary(aov(values~names))
#we reject

names = factor(names)
TukeyHSD(aov(values~names))
