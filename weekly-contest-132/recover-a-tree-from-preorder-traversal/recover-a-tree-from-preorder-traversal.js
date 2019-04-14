function TreeNode(val) {
    this.val = val
    this.left = this.right = null
}

const recoverFromPreorder = str => {
    const reg = /(\-*\d+)/g

    const parse_token = token => {
        let depth = 0
        const val = []
        for (const x of token) {
            if (x == '-') {
                depth += 1
                continue
            }
            val.push(x)
        }
        return { depth, val: +val.join('') }
    }

    const stack = []
    const h = tokens => {
        if (!tokens.length) {
            return
        }

        const token = tokens[0]
        const { depth, val } = parse_token(token)
        const node = new TreeNode(val)

        while (stack[stack.length - 1].depth >= depth) {
            stack.pop()
        }
        const { node: parent } = stack[stack.length - 1]
        if (parent.left) {
            parent.right = node
        } else {
            parent.left = node
        }
        stack.push({ depth, node })

        h(tokens.slice(1))
    }

    const tokens = str.match(reg)
    const root = new TreeNode(+tokens[0])
    stack.push({ node: root, depth: 0 })
    h(tokens.slice(1))

    return root
}

const serialize = root => {
    const r = []
    const queue = [root]
    while (queue.length) {
        const node = queue.shift()
        if (node) {
            r.push(node.val)
            queue.push(node.left)
            queue.push(node.right)
            continue
        }
        r.push('null')
    }

    console.log(r.join(', '))
}
serialize(recoverFromPreorder('1-2--3---4-5--6---7'))
