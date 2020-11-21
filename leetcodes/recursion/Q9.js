/**
 * @param {number} x
 * @return {boolean}
 */

// 用了字符串 没看题... 回头补上
var isPalindrome = function (x) {
    x = x.toString();
    if (x.length === 1) {
        return true;
    }
    if (x.length === 2) {
        return x[0] === x[1];
    }
    return isPalindrome(x.substring(1, x.length - 1)) && x[0] === x[x.length - 1]
};