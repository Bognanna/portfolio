#Ex.1
a1 = c(5,4,3,3,5)
b1 = c(1,4,6,0,8,5)

mean(a1) #mean
mean(b1)

var(a1) #variance
var(b1)

sd(a1) #standard deviation
sd(b1)

boxplot(a1, b1)
#boxplot(b1)

#Ex.2
a2 = c(2.45,3.6,2.8,2.45,3.0,2.8,2.6,2.8)
mean(a2) #2.864286
quantile(a2) #Q1 = 2.5625, Q2 = 2.8, Q3 = 2.85

var(a2) #0.1376786 mm^2
sd(a2) #0.3710506 mm
max(a2) - min(a2) #range = 1.15
quantile(a2, 0.75) - quantile(a2, 0.25) #quantile range = 0.2875
sd(a2)/mean(a2) #index of variance ~13.2 %

#Ex.3
#set_seed(345611)
a3 = rbinom(20,10,0.3) #binomial distribution
b3 = rbinom(20,10,0.3)
#...

#Ex.4 - session -> set working directory -> choose directory
data4 = read.csv("strawberries.csv", header = TRUE, sep = ";")
class(data4)

mean(na.omit(data4$crop2010))
var(na.omit(data4$crop2010))
sd(na.omit(data4$crop2010))

hist(na.omit(data4[1,0]), prob = TRUE)

name = c("crop200", "crop2010")

par(mfrow = c(1,2)) #defines how histograms are displayed
for(i in 1:2){
  hist(na.omit(data4[,i]), prob = TRUE, main = paste("Histogram of ", name[i]))
}

#Ex.5
x = c(6, 7, 10, 5, 10, 12, 11, 7, 7, 9, 10, 8, 16, 11)
hist(x, prob = TRUE, col = "blue", breaks = c(5,8,10,14,16))

table(x)
table(cut(x, sqrt(length(x))))

#Ex.8
  #COVARIANCE
  # + - when the values of the feature x increases, then the values of feature y
  #increases too
  # - - when the values of feature x increases, then the values of
  #feature y decreases
  
  #CORELATION
  # 0 - no linear relationship
  # 0-0.2 - very weak relationship
  # 0.2-0.4 - weak relationship
  # 0.4-0.6 - modearate relationship
  # 0.6-0.8 - strong relationship
  # 0.8-1.0 - very strong relationship
  # 1 - linear relationship

x8 = c(140, 140, 150, 152, 154, 164, 167)
y8 = c(6, 5.5, 6, 6.2, 6.7, 8, 9.5)

cov(x8,y8)
cor(x8, y8)

#Ex.9
data9 = read.csv("ranking.csv", header = TRUE, sep = ";")
mean(data9$X2010)
mean(data9$X2011)
sd(data9[,1]) #<=> sd(data9$x2010)
sd(data9[,2])

hist(data9$X2012)
hist(data9$X2013)





