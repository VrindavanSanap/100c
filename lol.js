async function lol(n) {
    data = await fetch(`https://hacker-news.firebaseio.com/v0/item/${n}.json`)
    data = await data.json()
    console.log(n)
}
for (let i = 0; i < 100; i++) {
    lol(i)
}