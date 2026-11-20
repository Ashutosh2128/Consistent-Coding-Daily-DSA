class Solution {
  public:
    int minFlips(string &s) {
        int cng1 = 0, cng2 = 0;
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != (i & 1 ? '0' : '1')) cng1++;
            if(s[i] != (i & 1 ? '1' : '0')) cng2++;
        }
        
        return min(cng1, cng2);
    }
};












// class Solution {
//   public:
//     int minFlips(string &s) {
//         bool getZero = false;
//         bool getOne = false;
//         int change = 0;
        
//         for(int i = 0; i < s.length(); i++) {
//             int ch = s[i];
            
//             if(ch == '0') {
//                 if(getZero == false) {
//                     getZero = true;
//                     getOne = false;
//                 }
//                 else {
//                     change++;
//                     if(s[i+1] == '0') {
//                         getZero = false;
//                         getOne = true;
//                     }
//                 }
//             }
//             else {
//                 if(getOne == false) {
//                     getOne = true;
//                     getZero = false;
//                 }
//                 else {
//                     change++;
//                     if(s[i+1] == '1') {
//                         getOne = false;
//                         getZero = true;
//                     }
//                 }
//             }
//         }
        
//         return change;
//     }
// };










// class Solution {
//   public:
//     int minFlips(string &s) {
//         bool getZero = false;
//         bool getOne = false;
//         int change = 0;
        
//         for(int i = 0; i < s.length(); i++) {
//             char ch = s[i];
            
//             if(ch == '0') {
//                 if(getZero) {
//                     change++;
//                     getZero = false;
//                     getOne = true;
//                 }
//                 else {
//                     getZero = true;
//                     getOne = false;
//                 }
//             }
//             else {
//                 if(getOne) {
//                     change++;
//                     getOne = false;
//                     getZero = true;
//                 }
//                 else {
//                     getOne = true;
//                     getZero = false;
//                 }
//             }
//         }
        
//         return change;
//     }
// };