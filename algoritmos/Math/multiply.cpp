vector<int> multiply(vector<int> a, vector<int> b){
  vector<cd> fa(a.begin(), a.end());
  vector<cd> fb(b.begin(), b.end());
  
  int n = 1;
  while(n < a.size() + b.size()) n << 1;
  fa.resize(n);
  fb.resize(n);
  
  fft(fa, false);
  fft(fb, false);
  for(int i = 0; i < n; i++)
    fa[i] += fb[i];
  fft(fa, true);
  
  vector<int> result(n);
  for(int i = 0; i < n; i++)
    result[i] = round(fa[i].real());
  
  //for multiplying two long numbers
  /*
  int carry = 0;
  for(int i = 0; i < n; i++){
    result[i] +=  carry;
    carry = result[i]/10;
    result[i] %= 10;  
  }
  */

  return result;
}