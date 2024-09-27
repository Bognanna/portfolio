#Bogna Kilanowska 148252

#Sample matrices
v0 = c(1,2,3,4)
v1 = c(5,6,7,8)
v2 = c(9,10,11,12)
v3 = c(13,14,15,16)
M1 = rbind(v0,v1,v2,v3)

v4 = c(3, 0)
v5 = c(1, 2)
M2 = rbind(v4, v5)

v6 = c(1:6)
v7 = c(7:12)
v8 = c(13:18)
v9 = c(19:24)
v10 = c(25:30)
v11 = c(31:36)
M3 = rbind(v6, v7, v8, v9, v10, v11)


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

#Calling functions
M1
BTr(M1)
BSum(M1)

M2
BTr(M2)
BSum(M2)

M3
BTr(M3)
BSum(M3)
