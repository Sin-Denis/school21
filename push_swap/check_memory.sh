#!/usr/bin/env bash
docker run -ti -v $PWD:/test memory-test:0.1 bash -c "cd /test/; make && ./push_swap 3 2 1"
