/**
 * @param {string} s
 * @return {string}
 */

// 使用桶计数
var sortString = function (s) {
  var answer = "";
  var bucket = [];
  var total = s.length;
  for (var i = 0; i < 26; ++i) {
    bucket.push(0);
  }
  for (var i = 0; i < total; i++) {
    ++bucket[s[i].charCodeAt() - 97];
  }
  var forward = true;
  while (total) {
    if (forward) {
      for (var i = 0; i < 26; ++i) {
        if (bucket[i] != 0) {
          answer += String.fromCharCode(i + 97);
          --bucket[i];
          --total;
        }
      }
    } else {
      for (var i = 25; i >= 0; --i) {
        if (bucket[i] != 0) {
          answer += String.fromCharCode(i + 97);
          --bucket[i];
          --total;
        }
      }
    }
    forward = !forward;
  }
  return answer;
}


// 未用桶计数
var sortString0 = function (s) {
  var ans = "";
  var minToMax = true;
  var char = String.fromCharCode(96);
  while (s !== "") {
    var index = -1;
    //console.log(s, index, ans, minToMax, char);
    for (var i = 0; i < s.length; i++) {
      if (minToMax) {
        if (s[i] > char) {
          if (index > -1) {
            index = s[i] < s[index] ? i : index;
          } else {
            index = i;
          }
        }
      } else {
        if (s[i] < char) {
          if (index > -1) {
            index = s[i] > s[index] ? i : index;
          } else {
            index = i;
          }
        }
      }
    }
    if (index !== -1) {
      ans += s[index];
      char = s[index];
      s = s.substring(0, index) + s.substring(index + 1);
      continue;
    }
    minToMax = !minToMax;
    if (minToMax) {
      char = String.fromCharCode(96);
    } else {
      char = String.fromCharCode(123);
    }
  }
  return ans;
};
