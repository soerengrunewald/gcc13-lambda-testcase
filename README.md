# Testcase

I see some strange behaviour with lambda captures in GCC13. Where the variable we capture does not point to the same variable we actually wanna point too.
This is new since I have updated to Fedora 38 and GCC13, it does not happen the GCC12 nor clang 16.
```
Thread 1 "Client" received signal SIGSEGV, Segmentation fault.
operator() (__closure=0x7fffffffbea0) at client.cc:169
169			if (*c)
(gdb) list
165		CURL* curl{ nullptr };
166		CURLcode ret{ 0 };
167	
168		auto _ = gsl::finally([c = &curl, d = &curl] {
169			if (*c)
170				curl_easy_cleanup(*c);
171			(void)d;
172		});
173	
(gdb) p c
$1 = (void ** const) 0x7fff00000000
(gdb) p d
$2 = (void ** const) 0x7fffffffbee8
(gdb) q
A debugging session is active.
```
