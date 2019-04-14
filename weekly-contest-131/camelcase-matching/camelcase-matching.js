/**
 * @param {string[]} queries
 * @param {string} pattern
 * @return {boolean[]}
 */
const camelMatch = (queries, pattern) => {
    const reg = new RegExp('^[a-z]*' + pattern.split('').join('[a-z]*') + '[a-z]*$')
    return queries.map(q => reg.test(q))
}

console.log(camelMatch(['FooBar', 'FooBarTest', 'FootBall', 'FrameBuffer', 'ForceFeedBack'], 'FB'))
