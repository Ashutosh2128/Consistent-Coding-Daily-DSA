const enigmaFunction = ({ message, messageKey }) => {
  const messageArr = message.split(" ");
  return messageArr.reduce((result, curr) => {
    if(parseInt(curr) % messageKey === 0) {
      return `${result} ${curr.replace(parseInt(curr), "")}`
    }
    return result;
  }, "").trim();
}