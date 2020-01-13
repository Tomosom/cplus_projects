SUBDIRS = ./array/static_array \
          ./array/dynamic_array \
          ./list/seq_list/static_list \
          ./list/seq_list/dynamic_list \
          ./list/link_list \
          ./list/link_list/static_link_list \
          ./list/link_list/circle_list \
          ./list/dual_link_list \
          ./list/dual_link_list/dual_circle_list \
          ./pointer/shared_pointer \
          ./pointer/smart_pointer \
          ./sort \
          ./stack_and_queue/stack/static_stack \
          ./stack_and_queue/stack/link_stack \
          ./stack_and_queue/queue/static_queue \
          ./stack_and_queue/queue/link_queue \
          ./tstring \
          ./tree \
          ./tree/gtree \
          ./tree/btree \

MAKEFLAGS = --no-print-directory

.PHONY:all
all:
	@list='$(SUBDIRS)'; \
	for subdir in $$list; \
		do \
			echo -e "\033[36m----->> make $$subdir\033[0m"; \
			pushd $$subdir > /dev/null; \
			make; \
			popd > /dev/null; \
		done

.PHONY:clean
clean:
	@list='$(SUBDIRS)'; \
	for subdir in $$list; \
		do \
			echo -e "\033[36m----->> clean $$subdir\033[0m"; \
			pushd $$subdir > /dev/null; \
			make clean; \
			popd > /dev/null; \
		done


#sudo dpkg-reconfigure dash
