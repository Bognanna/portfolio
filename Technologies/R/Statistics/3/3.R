#Ex.1
  #to calculate sd we have to use the formula:
  # D(X) = sqrt(E(x^2) - E(x)^2)

x1 = c(-2, -1, 0, 2, 3)
p1 = c(0.1, 0.2, 0.3, 0.2, 0.2) #sum to the 1

plot(x1, p1, type = "h")
discrete.histogram(x1, p1)

EX1 = sum(x1*p1)
Sd1 = sqrt(sum(x1*x1*p1) - EX1*EX1)

  # EY = E(3X + 2) = 3EX + E2 = 3*06 + 2 = 3.8
  # D^2(Y) = D^2(3X + 2) = D^2(3X) + D^2(2) = 9D^2(X) = 9 * 2.84 = 25.56

#Ex.2
x2 = c(-2, 5, 10)
p2 = c(9/13, 3/13, 1/13)
EX2 = sum(x2 * p2)
Sd2 = sum(x2*x2*p2 ) - EX2*EX2

1 - pbinom(3,7,0.1)
pbinom(2,7,0.1)

#HomeWork ex.14