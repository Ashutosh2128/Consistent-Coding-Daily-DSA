const extractReminderText = message => {
  const reminderKeywords = ["remind", "reminder", "reminders"];
  const connectionWords = ["to", "about", "me"];
  const sentenceToArr = message.split(" ");
  let result = [];
  let reminderFound = false;
  
  sentenceToArr.forEach((word, index) => {
    if(reminderFound) {
      if(connectionWords.includes(word.toLowerCase())) {
        result = sentenceToArr.slice(index + 1);
      }
    }
    else if(reminderKeywords.includes(word.toLowerCase())) {
      reminderFound = true;
      result = sentenceToArr.slice(index + 1);
    }
  })
  
  const finalRes = result.join(" ");
  return finalRes[0].toUpperCase() + finalRes.slice(1);
}