#Ex. 1
a1 = sinpi(2)
b1 = cos(3/4)
c1 = log(15, base = exp(1))
d1 = log(exp(1)^4, base = exp(1))

#Ex. 2
a2 = (6^3)*log(34, base = exp(1)) + sinpi(1/4)
b2 = 4^exp(1) - 2*sqrt(7)

#Ex. 3
a3 = c(1:10)

#Ex. 4
a4 = c(a3*2)

#Ex. 5
a5 = c(seq(102, 999, by=3))
la5 = length(a5)

#Ex. 6
z = c(2, 34, 56, 89, 101)

#Ex. 7
z1 = rep(z, 2)
z2 = rep(z, each = 3)

#Ex. 8
w1 = c(z[3])
w2 = c(z[-2])
w3 = c(z[z>3])

#Ex. 9
a = c(1, 3, 6, 2, 7, 4)
aa = length(a)
ab = a[3]
b = c(a[-4])
ada = sum(a)
adb = sum(b)
c = c(a[a>4])

#Ex. 10
a10 = c(2, 3, 0)
b10 = c(1, 2, 1)
c10 = c(-1, 1, 1)
A = rbind(a10, b10, c10)
aA = det(A)
tA = t(A)
cA = solve(A)
dA = A^2
eA = A * cA
fA = diag(A)
gb = c(A[,2])
hb = eigen(A) 
M = A[-1, -3]

#Ex. 11
n11 = 10
a11 = c(1:n11)
for(i in 1:n11){
  a11[i] = (i+1)^2
}

#Ex.12
a12 = c(1,2,3,4,5)
mean12 = mean(a12)
if(mean12 > a12[3]){
  mean12
} else if(mean12 == a12[3]){
  0
}else{
  a12[3]
}

#Ex. 13
a13 = c(2, -3, 6, 8, -1, 4)
n13 = 0

for(i in 1:length(a13)){
  if(a13[i]< 0){
    n13 = n13 + 1 
  }
}

id13 = (1:n13)
i13 = 0
for(i in 1:length(a13)){
  if(a13[i] < 0){
    i13 = i13 + 1
    a13[i] = a13[i]*(-1)
    id13[i13] = i
  }
}

#Ex. 14
x14 = c(10, 12, 14, 15, 20)
y14 = c(15, 20, 17, 11, 16)
plot(x14, y14)

#Ex. 15 (p - points, l - lines, b - both, c, o, h, n)
plot(x14,y14, type = "b")

#Ex, 16
plot(x14,y14, type = "l",main = "Car weight depending on the number kilometers traveled", xlab = "Kilometers traveled", ylab = "Car weight")

#Ex. 17
curve(sin(x), from = 0, to = 10)

#Ex. 18
#
#

#Ex. 19
Mtrace = function(A){
  tr = sum(diag(A))
  return(tr)
}

#Ex. 20
BTr = function(A){
  ij20 = c(dim(A))
  i20 = ij20[1]/2
  j20 = ij20[2]/2
  vec20 = c(0,0,0,0)
  for(i in 1:i20){
    vec20[1] = vec20[1] + A[2*(i-1)+1, 2*(i-1)+1]
    vec20[3] = vec20[3] + A[2*i, 2*(i-1)+1]
    vec20[2] = vec20[2] + A[2*(i-1)+1, 2*i]
    vec20[4] = vec20[4] + A[2*i, 2*i]
  }
  BT = matrix(vec20, ncol = 2, nrow = 2)
  BT = t(BT)
  return(BT)
}

#Ex. 21
BSum = function(A){
  ij21 = c(dim(A))
  i21 = ij21[1]/2
  j21 = ij21[2]/2
  vec21 = c(0,0,0,0)
  for(i in 1:i21){
    for(j in 1:j21){
      vec21[1] = vec21[1] + A[2*(i-1)+1, 2*(j-1)+1]
      vec21[3] = vec21[3] + A[2*i, 2*(j-1)+1]
      vec21[2] = vec21[2] + A[2*(i-1)+1, 2*j]
      vec21[4] = vec21[4] + A[2*i, 2*j]
    }
  }
  BT = matrix(vec21, ncol = 2, nrow = 2)
  BT = t(BT)
  return(BT)
}