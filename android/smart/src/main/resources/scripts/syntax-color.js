/**
 * This is about <code>Example.js</code>.
 * {@link com.yourCompany.aPackage.aFile}
 *
 * @author author
 * @deprecated use <code>BetterExample.js</code>
 */
var index = 0;
var arr = [];

function foo() {
    /* This comment may span multiple lines. */
    var var1 = new Object();
    var obj = {
        make : "Toyota",
        model : "Celica",
        year : 2000
    };
    var s = "abc123";
    clear(var1);
}

function pop() {
    return arr[index--];
}

function push(elem) {
    // This comment may span only this line
    arr[index++] = elem;
}

function isEmpty() {
    // TODO refactor
    return index == 0;
}
