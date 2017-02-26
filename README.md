# stz-curl #

libcurl bindings in Stanza. Early completely-broken version 0.0.1 not yet released even.

### How do I get set up? ###

Requires libcurl $VERSION.
Install with `gx` via the stanza-tools repo:
```
gx repo add <REPOADDR>
gx i stz-curl
```
Or pull the `pkg` directly with `wget`:
```
wget http://bitbucket.org/MadcapJake/stz-curl/release/0.0.1/curl.pkg
```
Then import the package as `curl` in your Stanza code:
```
defpackage my-curl-app :
    import core
	import curl
```

### Contribution guidelines ###

- File issues
- Provide feedback
- Use this package in your projects