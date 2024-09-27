#Ex.5,6,7
par(mfrow=c(1,3)) #to show all 3 histograms
for(i in 1:3){
  x5 = rnorm(2*10^i,10,3)
  hist(x5,prob = TRUE)
  curve(dnorm(x,10,3),add=TRUE)
}
