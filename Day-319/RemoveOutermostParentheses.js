/**
 * @param {string} s
 * @return {string}
 */
var removeOuterParentheses = function(s) {
    let ans = [];
    let temp = []
    let count = 0;

    s.split('').forEach(ch => {
        if(temp.length && count == 0) {
            ans = [...ans, ...temp.slice(1, -1)];
            temp = [];
        }

        temp.push(ch);
        count = ch === '(' ? count + 1 : count - 1;
    })

    // Check for last valid parenthesis string which is not checked due to loop end
    if(temp.length && count == 0) ans = [...ans, ...temp.slice(1, -1)];

    return ans.join('');
};










// /**
//  * @param {string} s
//  * @return {string}
//  */
// var removeOuterParentheses = function(s) {
//     let ans = [];
//     let temp = []
//     let count = 0;

//     s.split('').forEach(ch => {
//         if(temp.length && count == 0) {
//             temp.shift();
//             temp.pop();
//             ans = [...ans, ...temp];
//             temp = [];
//         }

//         temp.push(ch);
//         count = ch === '(' ? count + 1 : count - 1;
//     })

//     // Check for last valid parenthesis string which is not checked due to loop end
//     if(temp.length && count == 0) {
//         temp.shift();
//         temp.pop();
//         ans = [...ans, ...temp];
//     }

//     return ans.join('');
// };